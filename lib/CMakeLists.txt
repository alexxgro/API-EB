project(API_lib)

add_subdirectory(Server)


include_directories(
        /usr/local/include
)

add_library(API
        STATIC
        ${Server_Headers}
        ${Server_Sources}
        )
