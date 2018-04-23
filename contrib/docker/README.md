### Setup docker on Debian 8.1

Install notes: https://docs.docker.com/install/linux/docker-ce/debian/#install-using-the-repository

Docker CLI: https://docs.docker.com/engine/reference/run/

Script that installs docker-ce: `setup_docker_debian.sh`

### Build&Run EXTN docker container

Pre: `ExtensiveCoin.conf MUST be available under link EXTN_CONF_URL as pointed out in the Dockerfile`

Build container: `sudo docker build --tag extn:1.0.0 .`

Run container: `docker run -d --name extn.cont extn:1.0.0`

See if it is up: `docker ps -a`

Shell in the container: `docker exec -it extn.cont /bin/bash`

Test RPC: `extn-cli -rpcuser=extn -rpcpassword=<from config file> help`

Stop container: `docker stop extn.cont`
