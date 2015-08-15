from setuptools import setup, Extension

luffa_hash_module = Extension('luffa_hash',
                               sources = ['luffamodule.c',
                                          'luffa.c',
                                          '../../sph/luffa.c'],
                               include_dirs=['.', '../../sph'])

setup (name = 'luffa_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [luffa_hash_module])
