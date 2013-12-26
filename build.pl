#!/usr/bin/env perl

#Simple perl build script for osv1

use strict;
use warnings;
use feature ':5.16';

shift;

say "Visually inspect this output for errors in compilation.";
system('/home/cody/x-tools/i386-unknown-elf/bin/i386-unknown-elf-as ./boot/boot.s -o ./_bin/boot.o');
system('/home/cody/x-tools/i386-unknown-elf/bin/i386-unknown-elf-gcc -c main.c -o ./_bin/main.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra');
system('/home/cody/x-tools/i386-unknown-elf/bin/i386-unknown-elf-gcc -T ./_compilation/linker.ld -o ./_bin/osv1.bin -ffreestanding -O2 -nostdlib ./_bin/boot.o ./_bin/main.o -lgcc');
system('cp ./_bin/osv1.bin ./_bin/isodir/boot/osv1.bin');
system('cp ./_compilation/grub.cfg ./_bin/isodir/boot/grub/grub.cfg');
system('grub-mkrescue -o ./_bin/osv1.iso ./_bin/isodir');
