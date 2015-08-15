from setuptools import setup, Extension

whirlcoin_hash_module = Extension('whirlcoin_hash',
                                  sources = ['whirlcoinmodule.c',
                                          'whirlcoin.c',
                                          '../../sph/whirlpool.c'],
                                  include_dirs=['.', '../../sph'])

setup (name = 'whirlcoin_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by DoomCoin',
       test_suite = 'test',
       ext_modules = [whirlcoin_hash_module])
