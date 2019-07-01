set(apps_sources
    StackApp.cxx
    QueueApp.cxx
    )

set(apps_headers
    )

add_executable(StackApp  StackApp.cxx ${apps_headers})
add_executable(QueueApp  QueueApp.cxx ${apps_headers})

target_link_libraries(StackApp core)
target_link_libraries(QueueApp core)

set_target_properties(StackApp PROPERTIES FOLDER "Applications")
set_target_properties(QueueApp PROPERTIES FOLDER "Applications")

install(
    TARGETS
        StackApp
		QueueApp

	RUNTIME DESTINATION bin
)


install(DIRECTORY ${CMAKE_SOURCE_DIR}/../bin/
        DESTINATION bin
FILES_MATCHING PATTERN "*.sh"
PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_READ WORLD_EXECUTE
)