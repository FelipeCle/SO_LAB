void subNegMod(int m[][C], int lin) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] < 0)
                m[i][j] = abs(m[i][j]);
        }
    }
}
