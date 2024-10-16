# valgrind 使用
```c
valgrind  --track-origins=yes --show-reachable=yes  --leak-check=full ./<programname>
```
# valgrind 使用自動停下來
將 Valgrind 和 GDB 結合使用，這樣當 Valgrind 檢測到問題時，你可以使用 GDB 來跟蹤具體的位置。
```c
valgrind  --track-origins=yes --show-reachable=yes  --leak-check=full --vgdb=yes --vgdb-error=0 ./<programname>
```

如果用了malloc 要注意一定要free 