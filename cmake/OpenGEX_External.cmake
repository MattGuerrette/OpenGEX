
include(FetchContent)

if (NOT OPENDDL_DIR)
    FetchContent_Declare(OpenDDL
        GIT_REPOSITORY "https://github.com/MattGuerrette/OpenDDL.git"
        GIT_TAG dev/stl
    )
    FetchContent_MakeAvailable(OpenDDL)
else()
    add_subdirectory(${OPENDDL_DIR} OpenDDL)
endif()


