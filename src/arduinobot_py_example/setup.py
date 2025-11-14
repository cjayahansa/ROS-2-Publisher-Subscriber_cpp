from setuptools import find_packages, setup

package_name = 'arduinobot_py_example'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='cjayahansa',
    maintainer_email='cjayahansa@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'simple_publisher = arduinobot_py_example.simple_publisher:main',
            'simple_subscriber = arduinobot_py_example.simple_subscriber:main',
        ],
    },
)
