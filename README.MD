## linux exec hook demo

```bash

rm -rf exec-hook.so && make && chmod 777 exec-hook.so && cp exec-hook.so /usr/lib/ && cat << 'EOF' > /etc/ld.so.preload
/usr/lib/exec-hook.so
EOF

```