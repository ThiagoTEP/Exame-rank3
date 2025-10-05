#include <unistd.h> // read
#include <fcntl.h>  // open
#include <stdio.h>

int main(void)
{
    int fd;
    char buffer[11]; // vamos ler de 10 em 10 bytes (+1 pra '\0')
    ssize_t bytes_read;

    fd = open("text_read.txt", O_RDONLY); // abre arquivo para leitura
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    while ((bytes_read = read(fd, buffer, 10)) > 0)
    {
        buffer[bytes_read] = '\0'; // termina a string
        printf("Lido: [%s]\n", buffer);
    }

    close(fd);
    return 0;
}
