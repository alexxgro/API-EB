project(API_lib)

add_subdirectory(DTO)
add_subdirectory(Server)
add_subdirectory(Transactions)

include_directories(
        /usr/local/include
)

add_library(API
        STATIC
        ${DTO_Headers}
        ${DTO_Sources}
        ${Server_Headers}
        ${Server_Sources}
        ${Transactions_Headers}
        ${Transactions_Sources}
        )
