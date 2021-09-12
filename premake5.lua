workspace "ListRootDirs"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ListRootDirs"
	location "ListRootDirs"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outdir)
	objdir ("bin/intermediates/" .. outdir)

	pchheader "pch.h"
	pchsource "%{prj.name}/src/pch.cpp"

	warnings "Extra"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"
	filter "configurations:Debug"
        defines "PH_DEBUG"
		symbols "On"
	filter "configurations:Release"
        defines "PH_RELEASE"
		optimize "On"
    