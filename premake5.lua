workspace "Muzzle"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Muzzle"
	location "Muzzle"
	kind "SharedLib"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "mzpch.h"
	pchsource "Muzzle/src/mzpch.cpp"

	files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MZ_PLATFORM_WINDOWS",
			"MZ_BUILD_DLL",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "MZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MZ_DIST"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
	}

	includedirs
	{
		"Muzzle/vendor/spdlog/include",
		"Muzzle/src"
	}

	links "Muzzle"

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"MZ_PLATFORM_WINDOWS",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
		}

	filter "configurations:Debug"
		defines "MZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MZ_DIST"
		optimize "on"