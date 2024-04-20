int i;
    for (i = 0; i < 10; i++) {
        fwrite(&i, sizeof(int), 1, file);
    }
    fclose(file);
