from setuptools import find_packages
from setuptools import setup

setup(
    name='vacuum_msgs',
    version='0.1.0',
    packages=find_packages(
        include=('vacuum_msgs', 'vacuum_msgs.*')),
)
