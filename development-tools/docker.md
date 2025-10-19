# Things I actually use Docker For

https://www.youtube.com/watch?v=pBPRr9fOLBQ&list=PLUHtiHAczBHeFsBE0cPhMzWYzo6FKHjWN&index=5

- docker image - template that contains all the configs and files to create a container
- docker file - defines how an image will be configured
- docker container - simulated machines that run a docker image

1. avoid installing things

- pull docker image
- docker run - runs the image
- allows you to install things easier
- docker image ls - list all images
- docker ps - list docker containers
- docker ps -a - list all docker containers
- docker system prine --all --volumes

2. avoid dependencies

- easier to run a docker environment rather than a virtual environment
- allows you to not have to install one million different packages

![alt text](../images/image-3.png)

```
docker build -t indexer .
```

```
docker run --name NAME-CONTAINER NAME
```

3. Docker Compose - utility that allows you to define and run multiple contianers

- you can use a YAML file with a docker file
- you can use docker compose to setup a load balancer

```
docker compose up --build
```

4. CI/CD - automating the development process

![alt text](../images/image-4.png)

5. games with docker

- you can use docker to setup servers for games
- you use x11 forwarded to redirect the graphics to your computer
- you have to download the x11 server
