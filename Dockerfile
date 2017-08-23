# Dict-cli  Docker
FROM centos:latest
MAINTAINER gnaneshkunal@outlook.com
RUN yum update \
	&& yum install -y wget gcc libcurl-devel json-c make \
	&& curl --silent --location https://rpm.nodesource.com/setup_8.x |  bash - \
        && yum install -y nodejs \
	&& wget -O dict.tar.gz https://codeload.github.com/GnaneshKunal/dict/tar.gz/v1.1 \
	&& tar xvzf dict.tar.gz --strip-components 1 \
	&& wget -O json.tar.gz https://github.com/json-c/json-c/archive/json-c-0.12.1-20160607.tar.gz \
	&& tar -xvzf json.tar.gz \
	&& cd json-* \
	&& ./configure && make && make install \
	&& cd .. && make all \
    	&& echo "alias dict='./dict'" >> ~/.bashrc \
    	&& source ~/.bashrc \
	&& npm install \
	&& rm -rf /tmp/* /var/tmp/*
EXPOSE 8080
CMD ["npm", "start"]
