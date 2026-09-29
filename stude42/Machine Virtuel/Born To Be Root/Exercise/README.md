This activity has been created as part of the 42 curriculum by wineto-m.*
# Born2beroot

Projet de l'école 42 consistant à créer une machine virtuelle (Debian ou Rocky Linux) selon des règles de sécurité et d'administration système strictes, avec du chiffrement LVM, une politique de mots de passe forte, un pare-feu et un script de monitoring.

## 📋 Sommaire

- [Description](#description)
- [Prérequis](#prérequis)
- [Installation de la VM](#installation-de-la-vm)
- [Partitionnement (LVM)](#partitionnement-lvm)
- [Configuration du système](#configuration-du-système)
- [Politique de mots de passe](#politique-de-mots-de-passe)
- [Sudo](#sudo)
- [Pare-feu (UFW / firewalld)](#pare-feu-ufw--firewalld)
- [SSH](#ssh)
- [Script de monitoring](#script-de-monitoring)
- [Partie bonus](#partie-bonus)
- [Questions d'évaluation courantes](#questions-dévaluation-courantes)

## Description

Born2beroot a pour but d'apprendre les bases de la virtualisation et de l'administration système Linux : installation, sécurisation et configuration d'une machine, gestion des utilisateurs, des groupes, des permissions, et automatisation via un script shell.

## Prérequis

- VirtualBox ou UTM (selon l'OS de la machine hôte)
- Une image ISO de **Debian** (sans interface graphique) ou **Rocky Linux** selon le sujet fourni
- Au moins 2h30 de temps devant soi pour l'installation initiale

## Installation de la VM

1. Créer une nouvelle VM dans VirtualBox/UTM
2. Allouer les ressources (RAM ~1-2 Go, disque ~8-10 Go minimum)
3. Monter l'ISO d'installation
4. Choisir une installation **en mode texte, sans interface graphique**
5. Configurer le nom d'hôte (`hostname`) selon la convention demandée (souvent `login42`)

## Partitionnement (LVM)

Le sujet impose l'utilisation de **LVM (Logical Volume Manager)** avec chiffrement des partitions :

- `/` (root)
- `/home`
- `/var`
- `/var/log`
- `/tmp`
- `/srv`
- swap

Exemple de structure :
```
Disque physique → Partition chiffrée (LUKS) → Volume Group (VG) → Logical Volumes (LV)
```

Commandes utiles pour vérifier :
```bash
lsblk
sudo pvs   # Physical Volumes
sudo vgs   # Volume Groups
sudo lvs   # Logical Volumes
```

## Configuration du système

Après l'installation, penser à :

```bash
sudo apt update && sudo apt upgrade -y
sudo apt install sudo ufw libpam-pwquality -y
```

## Politique de mots de passe

Éditer `/etc/pam.d/common-password` et `/etc/login.defs` pour respecter les règles classiques du sujet :

- Longueur minimale de 10 caractères
- Au moins une majuscule et une minuscule
- Au moins un chiffre
- Pas plus de 3 caractères identiques consécutifs
- Ne doit pas contenir le nom d'utilisateur
- Expiration au bout de 30 jours, minimum 2 jours avant modification
- Avertissement 7 jours avant expiration

Exemple dans `/etc/pam.d/common-password` :
```
password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username enforce_for_root
```

Exemple dans `/etc/login.defs` :
```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

## Sudo

Configuration de sudo dans `/etc/sudoers.d/` (ne jamais éditer `/etc/sudoers` directement, utiliser `visudo`) :

```
Defaults        passwd_tries=3
Defaults        badpass_message="Mot de passe incorrect. Réessayez."
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        requiretty
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
```

Ne pas oublier de créer le dossier de log :
```bash
sudo mkdir /var/log/sudo
```

## Pare-feu (UFW / firewalld)

- Sur **Debian** : UFW, port SSH configuré sur un port non standard (ex : 4242)
```bash
sudo ufw enable
sudo ufw allow 4242
sudo ufw status
```

- Sur **Rocky Linux** : firewalld
```bash
sudo firewall-cmd --permanent --add-port=4242/tcp
sudo firewall-cmd --reload
```

## SSH

Éditer `/etc/ssh/sshd_config` :
```
Port 4242
PermitRootLogin no
```

Puis redémarrer le service :
```bash
sudo systemctl restart ssh    # Debian
sudo systemctl restart sshd   # Rocky
```

## Script de monitoring

Un script `monitoring.sh` doit afficher toutes les 10 minutes (via `crontab`) des informations système, diffusées à tous les terminaux avec `wall`.

Informations généralement affichées :
- Architecture et version du noyau
- Nombre de processeurs physiques
- Utilisation de la RAM (%)
- Utilisation du disque (%)
- Charge CPU (%)
- Dernier reboot
- État LVM (yes/no)
- Nombre de connexions TCP actives
- Nombre d'utilisateurs connectés
- Adresse IP et MAC
- Nombre de commandes exécutées avec sudo

Exemple d'entrée crontab (`sudo crontab -e`) :
```
*/10 * * * * /root/monitoring.sh
```

Exemple de squelette du script :
```bash
#!/bin/bash

arch=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
ram_total=$(free -m | awk '$1 == "Mem:" {print $2}')
ram_used=$(free -m | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
# ... compléter avec les autres métriques

wall "	#Architecture: $arch
	#CPU physiques: $pcpu
	#vCPU: $vcpu
	#Mémoire utilisée: $ram_used/$ram_total MB ($ram_percent%)"
```

## Partie bonus

Une fois la partie obligatoire validée à 100%, possibilité d'ajouter :
- Un serveur **WordPress** avec **Lighttpd**, **MariaDB** et **PHP**
- Un service supplémentaire au choix (ex : serveur mail, FTP...)
- Un script bash permettant de restaurer automatiquement les partitions LVM

## Questions d'évaluation courantes

- Différence entre Debian et CentOS/Rocky ?
- Qu'est-ce que LVM et pourquoi l'utiliser ?
- Pourquoi ne pas utiliser root directement ?
- Différence entre UFW et iptables ?
- Comment fonctionne le chiffrement des partitions ?
- Pourquoi changer le port SSH par défaut ?

---

> 💡 Astuce : gardez toujours une **VM de sauvegarde/snapshot** avant chaque étape critique (partitionnement, config sudo, SSH), car une erreur de config peut vous bloquer hors du système.
