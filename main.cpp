#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    if (!getuid()) {
        system("sed -i \"1s/.*/\\$nrconf{restart} = 'a';/\" /etc/needrestart/needrestart.conf");
        system("apt update -y");
        sleep(1);
        system("apt install git wget build-essential autoconf libtool bison re2c pkg-config libssl-dev libbz2-dev libcurl4-openssl-dev libffi-dev libzip-dev libpng-dev libjpeg-dev libwebp-dev libavif-dev libgmp-dev libc-client-dev libkrb5-dev libldap2-dev libonig-dev libreadline-dev libsodium-dev libxml2-dev libsqlite3-dev -y");

        sleep(1);


        chdir("~");
        system("wget https://openlitespeed.org/packages/openlitespeed-1.7.16.src.tgz");
        system("tar -xvf openlitespeed-1.7.16.src.tgz");
        chdir("./openlitespeed-1.7.16");
        system("chmod +x ./build.sh");
//        sleep(1);
//        system("./build.sh");
//        sleep(1);
//        system("./install.sh");
//        sleep(1);

//        exit(1);

        chdir("../");
        system("git clone https://github.com/libexpat/libexpat.git");
        sleep(1);
        chdir("./libexpat");
        chdir("./expat");
        system("chmod +x ./buildconf.sh");
        system("./buildconf.sh");
        sleep(1);
        system("chmod +x ./configure");
        system("./configure");
        sleep(1);
        system("make install");
        sleep(1);
        system("cp ./lib/.libs/libexpat* /lib/");

        chdir("../..");
        system("wget https://www.php.net/distributions/php-5.6.35.tar.gz");
        system("tar -xvf php-5.6.35*");
        chdir("./php-5.6.35");

//        system("./configure --with-config-file-path=../conf --disable-all --with-litespeed --enable-session --enable-posix --enable-xml --with-libexpat-dir=/lib/ --with-zlib --enable-sockets --enable-bcmath --enable-json");
//        sleep(1);
//
//        system("rm ./Zend/zend_multiply.h");
//        system("wget https://raw.githubusercontent.com/TheBartle/auto-openlitespeed-install-on-arm-aarch/main/Zend/zend_multiply.h -P ./Zend/zend_multiply.h");
//        sleep(1);
//
//        system("make && make install");
//        sleep(1);
//
//        chdir("/usr/local/lsws/admin/fcgi-bin/");
//        system("rm -rf /usr/local/lsws/admin/fcgi-bin/admin_php");
//        system("cp /usr/local/bin/lsphp /usr/local/lsws/admin/fcgi-bin/admin_php");
//        system("rm -rf /usr/local/lsws/fcgi-bin/lsphp*");
//        system("cp /usr/local/bin/lsphp /usr/local/lsws/fcgi-bin/lsphp");
//        system("cp /usr/local/bin/lsphp /usr/local/lsws/fcgi-bin/lsphp5");
//
//
//        system("bash /usr/local/lsws/admin/misc/admpass.sh");
//        system("systemctl restart lsws");
//
//        system("sed -i \"1s/.*/\\$nrconf{restart} = 'i';/\" /etc/needrestart/needrestart.conf");
//
//        printf("*****************************************************************************");
//        printf("\\033[0;32mFinished");


    } else {
        printf("Run as root bro...");
    }

    return 0;
}
