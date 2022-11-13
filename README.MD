## linux exec hook demo

```bash

rm -rf exec-hook.so && make && chmod 644 exec-hook.so && cp exec-hook.so /lib64/ && cat << 'EOF' > /etc/ld.so.preload
/lib64/exec-hook.so
EOF

```