.PHONY: build

clean:
	rm -rf dist/* build/*

build:
	pipenv run --three python setup.py build
	pipenv run --three python setup.py sdist

test:
	pipenv install --three --dev
	pipenv run --three python setup.py build
	pipenv run --three python setup.py install
	pipenv run --three pytest

deploy: clean build
	pipenv install --three twine
	pipenv run --three twine upload dist/*
	pipenv uninstall --three twine