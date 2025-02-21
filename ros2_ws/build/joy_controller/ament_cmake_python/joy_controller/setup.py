from setuptools import find_packages
from setuptools import setup

setup(
    name='joy_controller',
    version='0.0.0',
    packages=find_packages(
        include=('joy_controller', 'joy_controller.*')),
)
