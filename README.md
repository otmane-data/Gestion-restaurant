
# 🍽️ Gestion de Restaurant en C

Ce projet est une application console en langage **C** permettant de gérer efficacement les **tables**, **commandes**, **menus** et **stocks** d’un restaurant. Il est conçu pour offrir une expérience simple et structurée aux utilisateurs.

---

## 🛠️ Fonctionnalités

### 📌 Gestion des Tables
- ✅ Affichage de l’état des tables (*libre* ou *occupée*)  
- ✅ Modification du statut d’une table  
- ✅ Sauvegarde de l’état dans un fichier (`etat_tables.txt`)  

### 📋 Gestion du Menu
- ✅ Affichage du menu avec prix  
- ✅ Ajout / suppression / modification de plats  
- ✅ Enregistrement dans `nouveau_menu.txt`  

### 🧾 Gestion des Commandes
- ✅ Prise de commande pour une table  
- ✅ Calcul automatique du total  
- ✅ Génération d’une facture  

### 🧂 Gestion des Stocks
- ✅ Suivi des ingrédients disponibles  
- ✅ Mise à jour des quantités après chaque commande  

---

## 📁 Structure du Projet

```
📦 gestion-restaurant
 ┣ 📜 main.c              → Point d’entrée du programme
 ┣ 📜 gerant.c            → Fonctions de gestion (menu, stock, commandes...)
 ┣ 📄 etat_tables.txt     → État des tables (libre / occupée)
 ┣ 📄 les aliments.txt    → Menu de base avec plats & prix
 ┣ 📄 nouveau_menu.txt    → Menu mis à jour par l’utilisateur
 ┗ 📄 README.md           → Documentation
```

---

## 🚀 Comment l’Utiliser

1. **Compiler le programme** (avec GCC par exemple) :
   ```bash
   gcc main.c -o gestion_restaurant
   ```

2. **Lancer le programme** :
   ```bash
   ./gestion_restaurant
   ```

3. **Naviguer dans le menu principal** pour :
   - Voir les tables
   - Modifier le menu
   - Passer une commande
   - Générer une facture

---

## 💡 Exemples d’Utilisation

- 🪑 **Afficher les tables** : Option 1 dans le menu  
- 📝 **Modifier une table** : Option 2  
- 🍽️ **Passer une commande** : Saisir les plats et quantités, puis générer la facture  

---

## 👥 Auteurs

-Bourabaa

---

## 📄 Licence

Ce projet est sous licence **[Nom de la licence]**.  

---

