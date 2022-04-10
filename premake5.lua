workspace "PacketEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Shipment"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PacketEngine"
	location "PacketEngine"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PACKET_PLATFORM_WINDOWS",
			"PACKET_BUILD_DLL"
		}

		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		--}

	filter "configurations:Debug"
		defines "PACKET_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PACKET_RELEASE"
		optimize "On"

	filter "configurations:Shipment"
		defines "PACKET_SHIPMENT"
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
		"PacketEngine/vendor/spdlog/include",
		"PacketEngine/src"
	}

	links
	{
		"PacketEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PACKET_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PACKET_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PACKET_RELEASE"
		optimize "On"

	filter "configurations:Shipment"
		defines "PACKET_SHIPMENT"
		optimize "On"