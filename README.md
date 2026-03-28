&#9287@ajjqm_


This is my first GitHub project
<p>
this tells bout Cipher methis and give
<b>hi creating branch
git checkout -b feature1
<p>f1 branch update

git checkout -b feature1h
hiii
how are you

#!/bin/bash

read -sp "Enter a Password: " num
echo

if [[ $num =~ [0-9] ]] && \
   [[ $num =~ [A-Z] ]] && \
   [[ $num =~ [a-z] ]] && \
   [[ $num =~ [#!@\$%\^&*()_+=-] ]] && \
   [[ ${#num} -ge 8 && ${#num} -le 20 ]]
then
    echo "Strong Password"
else
    echo "Bad Password"
fi

jAjamr=[kNqoy$


<VirtualHost *:80>
    ServerName freshmart.com
    ServerAlias www.freshmart.com

    DocumentRoot /home/freshmart/public_html

    <Directory /home/freshmart/public_html>
        AllowOverride All
        Require all granted
    </Directory>

    ErrorLog /var/log/httpd/freshmart_error.log
    CustomLog /var/log/httpd/freshmart_access.log combined
</VirtualHost>