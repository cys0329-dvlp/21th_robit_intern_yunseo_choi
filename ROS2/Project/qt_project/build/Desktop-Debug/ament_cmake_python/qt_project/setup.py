from setuptools import find_packages
from setuptools import setup

setup(
    name='qt_project',
    version='0.0.0',
    packages=find_packages(
        include=('qt_project', 'qt_project.*')),
)
