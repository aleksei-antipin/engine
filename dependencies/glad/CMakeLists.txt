FILE(GLOB TPR_GLAD_SRC  src/*.c )


add_library (   glad
        STATIC
        ${TPR_GLAD_SRC} )


target_include_directories (glad
        PRIVATE           include
        SYSTEM INTERFACE  include
)


target_compile_options (glad
        PRIVATE
        -Wno-language-extension-token
)

set_target_properties (glad PROPERTIES PREFIX "")
set_target_properties (glad PROPERTIES OUTPUT_NAME "glad" )