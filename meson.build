project('argument', 'cpp', version : '1.0', default_options : ['cpp_std=c++20'])

sources = []
inc = include_directories('include')

subdir('src')

argument_shared_dep = declare_dependency(include_directories : inc,
  link_with : shared_lib)
argument_static_dep = declare_dependency(include_directories : inc,
  link_with : static_lib)
