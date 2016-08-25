ldapsearch -QLLL "(uid=z*)" cn | sed -n '/cn:/p' | sed 's/cn: //g' | sort -r -f
