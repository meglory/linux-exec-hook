## linux exec hook demo

```bash

unset LD_PRELOAD && rm -rf exec-hook.so && make && chmod a+x exec-hook.so && sudo cp exec-hook.so /usr/lib/

cat << 'EOF' > /etc/ld.so.preload
/usr/lib/exec-hook.so
EOF

```

