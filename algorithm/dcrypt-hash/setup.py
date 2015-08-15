from setuptools import setup, Extension

dcrypt_hash_module = Extension('dcrypt_hash', sources = ['dcryptmodule.c', 'dcrypt.c', 'dcrypt_sha256.c'],
    libraries=['ssl', 'crypto'])

setup (name = 'dcrypt_hash',
       version = '1.0',
       test_suite = 'test',
       ext_modules = [dcrypt_hash_module])
