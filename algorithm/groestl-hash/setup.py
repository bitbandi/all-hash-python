from setuptools import setup, Extension

groestl_hash_module = Extension('groestl_hash',
                                sources = ['groestlmodule.c',
                                           'groestl.c',
                                           '../../sph/groestl.c'],
                                include_dirs=['.', '../../sph'])


setup (name = 'groestl_hash',
       version = '0.1',
       description = 'Bindings for Groestl Used by MyriadCoin',
       test_suite = 'test',
       ext_modules = [groestl_hash_module])
