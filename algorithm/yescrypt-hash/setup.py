from setuptools import setup, Extension

yescrypt_hash_module = Extension('yescrypt_hash', sources = ['yescryptmodule.c'])

setup (name = 'yescrypt_hash',
       version = '1.0',
       test_suite = 'test',
       ext_modules = [yescrypt_hash_module])
