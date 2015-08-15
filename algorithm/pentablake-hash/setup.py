from setuptools import setup, Extension

pentablake_hash_module = Extension('pentablake_hash',
                                   sources = ['pentablakemodule.c',
                                              'pentablake.c',
                                              '../../sph/blake.c'],
                               include_dirs=['.', '../../sph'])


setup (name = 'pentablake_hash',
       version = '0.1',
       description = 'Bindings for pentablake Used by MyriadCoin',
       test_suite = 'test',
       ext_modules = [pentablake_hash_module])
