workspace "Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/ThirdParty/spdlog/include",
		"%{prj.name}/ThirdParty/sfml/include",
		"%{prj.name}/ThirdParty/vector"
	}
	
	libdirs
	{
		"%{prj.name}/ThirdParty/sfml/lib"
	}
	
	links
	{
		"sfml-graphics", "sfml-window", "sfml-system"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ENGINE_PLATFORM_WINDOWS",
			"ENGINE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} ThirdParty/sfml/bin ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "ENGINE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ENGINE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ENGINE_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Engine/src",
		"Engine/ThirdParty/spdlog/include",
		"Engine/ThirdParty/sfml/include",
		"Engine/ThirdParty/vector"
	}

	libdirs 
	{
		"Engine/ThirdParty/sfml/lib"
	}
	
	links
	{
		"Engine", "sfml-graphics", "sfml-window", "sfml-system"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ENGINE_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "ENGINE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ENGINE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "ENGINE_DIST"
			optimize "On"