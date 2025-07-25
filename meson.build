project('argument', 'cpp', version: '1.0', default_options: ['cpp_std=c++17'])

app_sources = files()

main_sources = files()

test_sources = files()

doctest_dep = dependency('doctest')

# Основной исполняемый файл
# executable('argument', main_sources + app_sources)

# Исполняемый файл для тестов
# test_exe = executable('argument-test', test_sources, dependencies: [doctest_dep])

# Зарегистрировать тест
# test('argument-test', test_exe)

static_lib = static_library('argument', app_sources, install : true)
shared_lib = shared_library('argument', app_sources, install : true)

argument_dep = declare_dependency(link_with : shared_lib)
argument_static_dep = declare_dependency(link_with : static_lib)