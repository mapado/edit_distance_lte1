from distutils.core import setup, Extension

lte1_edit_distance_module = Extension(
    '_edit_distance_lte1',
    sources = ['./edit_distance_lte1/_edit_distance_lte1.c']
)


setup(
    name='edit_distance_lte1',
    version='0.0.2',
    description='Fast string distance function for the case where the distance is less or equal to 1',
    include_package_data=True,

    author='Romain SENESI',
    author_email='romain.senesi@mapado.com',
    maintainer='Romain SENESI',
    maintainer_email='romain.senesi@mapado.com',
    url='https://github.com/mapado/edit_distance_lte1',
    packages=['edit_distance_lte1'],
    license=['MIT'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development :: Libraries :: Python Modules'
    ],
    ext_modules=[lte1_edit_distance_module]
)
