#include <stdio.h>
#include <string.h>  // Inclure ceci pour memcpy
#include "common.h"
#include "ip.h"

// Fonction pour analyser l'en-tête IP et extraire les adresses IP source et destination
void analyserIP(char *trame, IP *ip) {
    int ip_header_start = 14;  // Début de l'en-tête IP dans la trame

    // Copier l'adresse IP source (4 octets) à partir de la trame
    memcpy(&ip->sourceIP, &trame[ip_header_start + 12], 4);

    // Copier l'adresse IP destination (4 octets) à partir de la trame
    memcpy(&ip->destinationIP, &trame[ip_header_start + 16], 4);

    // Afficher l'adresse IP source
    printf("Adresse IP source : %d.%d.%d.%d\n", 
        (unsigned char)(ip->sourceIP >> 24) & 0xFF, 
        (unsigned char)(ip->sourceIP >> 16) & 0xFF,
        (unsigned char)(ip->sourceIP >> 8) & 0xFF, 
        (unsigned char)ip->sourceIP & 0xFF);

    // Afficher l'adresse IP destination
    printf("Adresse IP destination : %d.%d.%d.%d\n", 
        (unsigned char)(ip->destinationIP >> 24) & 0xFF, 
        (unsigned char)(ip->destinationIP >> 16) & 0xFF,
        (unsigned char)(ip->destinationIP >> 8) & 0xFF, 
        (unsigned char)ip->destinationIP & 0xFF);
}

// Fonction pour afficher les détails de l'en-tête IP
void afficherIP(IP ip)
{
    printf("IP:\n");
    printf("    version: %d\n", ip.version);
    printf("    IHL: %d\n", ip.IHL);
    printf("    typeOfService: %d\n", ip.typeOfService);
    printf("    totalLength: %d\n", ip.totalLength);
    printf("    identification: %d\n", ip.identification);
    printf("    flags: %d\n", ip.flags);
    printf("    fragmentOffset: %d\n", ip.fragmentOffset);
    printf("    timeToLive: %d\n", ip.timeToLive);
    printf("    protocol: %d\n", ip.protocol);
    printf("    HeaderChecksum: %d\n", ip.HeaderChecksum);
    printf("    sourceIP: ");
    afficherIPAddress(ip.sourceIP);  // Appeler la fonction pour afficher l'adresse IP source
    printf("\n    destinationIP: ");
    afficherIPAddress(ip.destinationIP);  // Appeler la fonction pour afficher l'adresse IP destination
    printf("\n");
}

// Fonction pour afficher une adresse IP au format décimal pointé
void afficherIPAddress(unsigned int address) {
    printf("%d.%d.%d.%d", 
        (unsigned char)(address >> 24) & 0xFF, 
        (unsigned char)(address >> 16) & 0xFF,
        (unsigned char)(address >> 8) & 0xFF, 
        (unsigned char)address & 0xFF);
}

