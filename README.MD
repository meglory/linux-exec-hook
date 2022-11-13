## linux exec hook demo

```bash

## alibaba cloud linux

yum install -y git

git clone https://github.com/meglory/linux-exec-hook.git

cd linux-exec-hook && rm -rf exec-hook.so && make && chmod 644 exec-hook.so && cp exec-hook.so /lib64/ && cat << 'EOF' > /etc/ld.so.preload
/lib64/exec-hook.so
EOF



```