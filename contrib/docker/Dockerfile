FROM debian:jessie
MAINTAINER pavik - https://github.com/pavik

ENV EXTN_VERSION=1.0.0 \
 EXTN_USER=extn

ENV EXTN_URL=https://github.com/ExtensiveCoin/ExtensiveCoin/releases/download/v$EXTN_VERSION-linux/ExtensiveCoin-$EXTN_VERSION-x86_64-linux-gnu.tar.gz \
 EXTN_CONF=/home/$EXTN_USER/.ExtensiveCoin/ExtensiveCoin.conf \
 EXTN_CONF_URL=https://raw.githubusercontent.com/ExtensiveCoin/ExtensiveCoin/master/ExtensiveCoin.conf

RUN apt-get -qq update && \
apt-get install -yq wget ca-certificates pwgen && \
rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
wget $EXTN_URL -O /tmp/extn.tar.gz && \
mkdir -p /opt && \
cd /opt && \
tar xvzf /tmp/extn.tar.gz && \
rm /tmp/extn.tar.gz && \
ln -sf extn-$EXTN_VERSION extn && \
ln -sf /opt/extn/bin/extnd /usr/local/bin/extnd && \
ln -sf /opt/extn/bin/extn-cli /usr/local/bin/extn-cli && \
ln -sf /opt/extn/bin/extn-tx /usr/local/bin/extn-tx && \
adduser --uid 1000 --system ${EXTN_USER} && \
mkdir -p /home/${EXTN_USER}/.ExtensiveCoin/ && \
chown -R ${EXTN_USER} /home/${EXTN_USER} && \
echo "success: $EXTN_CONF"

USER extn
RUN wget $EXTN_CONF_URL -O $EXTN_CONF && \
    sed -i -e 's/\*your$username\*/extn/g' ${EXTN_CONF} && \
    sed -i -e 's/\*your$password\*/'`pwgen 32 1`'/g' ${EXTN_CONF} && \
    echo "Success"

EXPOSE 51572
VOLUME ["/home/extn/.ExtensiveCoin"]
WORKDIR /home/extn

ENTRYPOINT ["/usr/local/bin/extnd"]