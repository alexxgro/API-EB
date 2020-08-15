project(srcAPI)

include_directories(
        /usr/local/include
)

link_directories(
        /usr/local/lib
)

add_definitions(-DBOOST_LOG_DYN_LINK)

set(SRCAPI_Headers

        )

set(SRCAPI_Sources
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ../lib/Server/Routes.h ../lib/Server/Routes.cpp ../lib/DTO/DataStorage.h ../lib/DTO/DataStorage.cpp ../lib/Transactions/Transactions.cpp ../lib/Transactions/Transactions.h)

add_executable(srcAPI
        ${SRCAPI_Sources}
        ${SRCAPI_Sources}
        )

target_link_libraries(srcAPI boost_system pthread)

