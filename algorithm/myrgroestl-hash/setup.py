from setuptools import setup, Extension

myrgroestl_hash_module = Extension('myrgroestl_hash',
                                   sources = ['myrgroestlmodule.c',
                                              'myrgroestl.c',
                                              '../../sph/groestl.c',
                                              '../../sph/sha2.c'],
                                   include_dirs=['.', '../../sph'])


setup (name = 'myrgroestl_hash',
       version = '0.1',
       description = 'Bindings for myrgroestl Used by MyriadCoin',
       test_suite = 'test',
       ext_modules = [myrgroestl_hash_module])
