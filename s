option domain-name "ditiss.com";
option domain-name-servers 192.168.127.132, 192.168.127.200, 192.168.127.2;

default-lease-time 600;
max-lease-time 7200;

authoritative;
allow bootp;

subnet 192.168.127.0 netmask 255.255.255.0 {
    range 192.168.127.150 192.168.127.190;
    option routers 192.168.127.2;
    option subnet-mask 255.255.255.0;
    option broadcast-address 192.168.127.255;
}



nmcli connection modify ens160 ipv4.addresses 192.168.127.132/24
nmcli connection modify ens160 ipv4.gateway 192.168.127.2
nmcli connection modify ens160 ipv4.method manual
nmcli connection modify ens160 connection.autoconnect yes