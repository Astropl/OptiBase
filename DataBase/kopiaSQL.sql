--
-- Plik wygenerowany przez SQLiteStudio v3.2.1 dnia czw. sty 21 13:06:57 2021
--
-- U¿yte kodowanie tekstu: System
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Tabela: dbbaza
CREATE TABLE dbbaza (
    id                   INTEGER PRIMARY KEY,
    dbbaza_urzadzenia_id TEXT,
    dbbaza_kontrahent_id TEXT,
    FOREIGN KEY (
        dbbaza_urzadzenia_id
    )
    REFERENCES urzadzenia (id),
    FOREIGN KEY (
        dbbaza_kontrahent_id
    )
    REFERENCES kontrahenci (id) 
);

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       1,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       2,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       3,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       4,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       5,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       6,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       7,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       8,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       9,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       10,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       11,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       12,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       13,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       14,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       15,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       16,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       17,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       18,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       19,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       20,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       21,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       22,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       23,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       24,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       25,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       26,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       27,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       28,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       29,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       30,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       31,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       32,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       33,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       34,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       35,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       36,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       37,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       38,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       39,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       40,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       41,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       42,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       43,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       44,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       45,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       46,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       47,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       48,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       49,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       50,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       51,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       52,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       53,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       54,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       55,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       56,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       57,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       58,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       59,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       60,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       61,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       62,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       63,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       64,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       65,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       66,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       67,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       68,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       69,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       70,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       71,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       72,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       73,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       74,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       75,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       76,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       77,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       78,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       79,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       80,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       81,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       82,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       83,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       84,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       85,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       86,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       87,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       88,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       89,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       90,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       91,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       92,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       93,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       94,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       95,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       96,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       97,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       98,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       99,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       100,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       101,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       102,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       103,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       104,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       105,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       106,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       107,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       108,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       109,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       110,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       111,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       112,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       113,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       114,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       115,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       116,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       117,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       118,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       119,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       120,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       121,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       122,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       123,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       124,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       125,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       126,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       127,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       128,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       129,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       130,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       131,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       132,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       133,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       134,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       135,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       136,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       137,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       138,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       139,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       140,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       141,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       142,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       143,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       144,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       145,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       146,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       147,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       148,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       149,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       150,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       151,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       152,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       153,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       154,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       155,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       156,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       157,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       158,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       159,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       160,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       161,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       162,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       163,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       164,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       165,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       166,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       167,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       168,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       169,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       170,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       171,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       172,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       173,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       174,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       175,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       176,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       177,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       178,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       179,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       180,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       181,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       182,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       183,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       184,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       185,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       186,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       187,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       188,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       189,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       190,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       191,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       192,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       193,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       194,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       195,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       196,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       197,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       198,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       199,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       200,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       201,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       202,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       203,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       204,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       205,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       206,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       207,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       208,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       209,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       210,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       211,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       212,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       213,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       214,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       215,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       216,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       217,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       218,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       219,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       220,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       221,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       222,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       223,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       224,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       225,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       226,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       227,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       228,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       229,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       230,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       231,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       232,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       233,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       234,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       235,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       236,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       237,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       238,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       239,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       240,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       241,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       242,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       243,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       244,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       245,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       246,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       247,
                       '2',
                       '1'
                   );

INSERT INTO dbbaza (
                       id,
                       dbbaza_urzadzenia_id,
                       dbbaza_kontrahent_id
                   )
                   VALUES (
                       248,
                       '2',
                       '1'
                   );


-- Tabela: dBPrzypomnienie
CREATE TABLE dBPrzypomnienie (
    id                       INTEGER PRIMARY KEY,
    nr_wpisu                 TEXT    UNIQUE,
    data                     TEXT,
    temat                    TEXT,
    tresc                    TEXT,
    przypomnienie            TEXT,
    data_przypomnienia       TEXT,
    tekst_przypomnienia      TEXT,
    urzadzenia_numer_seryjny TEXT,
    FOREIGN KEY (
        urzadzenia_numer_seryjny
    )
    REFERENCES urzadzenia (numerSeryjny) 
);

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                1,
                                '2020/12/22/42',
                                '20201222',
                                'Instalacja',
                                'By³$em osobiœcie. Instalacja i szybkie szkolenie. Pani Asia bardzo zadowolona',
                                'TAK',
                                '2021:12:22',
                                'Zapytanie o przegl¹d',
                                'AP000363-20200720'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                2,
                                '2020/12/22/18468',
                                '20201222',
                                'Testowo',
                                'Czy bêdzie siê wyswiet³a³a informacja',
                                'NIE',
                                '2020:12:22',
                                '',
                                '1adgsdgs1'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                3,
                                '2020/12/22/6335',
                                '20201222',
                                'Testowo',
                                'Jeszcze inny analizator',
                                'TAK',
                                '2021:12:22',
                                'Brak przypomneineia',
                                '4hdgdhfgjhf4'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                4,
                                '2020/12/22/26501',
                                '20201222',
                                'Drugi Wpis terstowy',
                                'Drugi Wpis terstowy',
                                'TAK',
                                '2020:12:22',
                                'Drugi Wpis terstowy',
                                'AP000363-20200720'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                5,
                                '2021/01/08/42',
                                '20210108',
                                'Pomoc Techniczna',
                                '2020.12.26. Podes³anie linka do programu BodyPass',
                                'NIE',
                                '2021:1:8',
                                '',
                                'CDPL0002-20151028'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                6,
                                '2021/01/08/18468',
                                '20210108',
                                'Wysy³ka',
                                'Dzisiaj wysy³ka.
+ Siedzisko+ Stolik',
                                'NIE',
                                '2021:1:8',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                7,
                                '2021/01/08/6335',
                                '20210108',
                                'Wysy³ka',
                                'Potwierdzam: wysz³o.',
                                'NIE',
                                '2021:1:8',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                8,
                                '2021/01/11/42',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                9,
                                '2021/01/11/43',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                10,
                                '2021/01/11/44',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                11,
                                '2021/01/11/98',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                12,
                                '2021/01/11/99',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                13,
                                '2021/01/11/100',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                14,
                                '2021/01/11/101',
                                '20210111',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:11',
                                '',
                                'BJ000011-20201020'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                15,
                                '2021/01/11/102',
                                '20210111',
                                'Wydanie towaru',
                                '2021.01.11
Wydanie towaru. Pani Ola przyjecha³a osobiscie',
                                'NIE',
                                '2021:1:11',
                                '',
                                'C200008190'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                16,
                                '2021/01/11/103',
                                '20210111',
                                'Wydanie towaru',
                                '2021.01.11
Wydanie towaru. Pani Ola przyjecha³a osobiscie',
                                'NIE',
                                '2021:1:11',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                17,
                                '2021/01/12/104',
                                '20210112',
                                'Wysy³ka',
                                '2021.01.13 - Dzisiaj Wysy³ka',
                                'TAK',
                                '2022:1:12',
                                'Przegl¹d',
                                'AN000108-20201005'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                18,
                                '2021/01/14/105',
                                '20210114',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:1:14',
                                '',
                                '1adgsdgs1'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                19,
                                '2021/01/14/106',
                                '20210114',
                                'Testowo',
                                'dhhtjyj',
                                'NIE',
                                '2021:1:14',
                                '',
                                '1adgsdgs1'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                20,
                                '2021/01/14/107',
                                '2021:01:14',
                                'Testowo',
                                'Tstowwo',
                                'NIE',
                                '2021:1:14',
                                '',
                                '2fhdhdr2'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                21,
                                '2021/01/14/108',
                                '2021:01:14',
                                'Testowo',
                                'testowow',
                                'NIE',
                                '2021:1:14',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                22,
                                '2021/01/14/109',
                                '2021:01:14',
                                'Testowo',
                                'testrewe',
                                'TAK',
                                '2021:01:14',
                                'hnghfhfh',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                23,
                                '2021/01/15/110',
                                '2021:01:15',
                                'Testowo',
                                'Znów test',
                                'NIE',
                                '2021:01:15',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                24,
                                '2021/01/15/111',
                                '2021:01:15',
                                'Testowo dla przypomnienia',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:01:15',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                25,
                                '2021/01/15/112',
                                '2021:01:15',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'TAK',
                                '2021:01:15',
                                'bsdfbfdbdf',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                26,
                                '2021/01/15/113',
                                '2021:01:15',
                                'Testowo',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:01:15',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                27,
                                '2021/01/15/114',
                                '2021:01:15',
                                'Bez Przypom.',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:01:15',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                28,
                                '2021/01/15/115',
                                '2021:01:15',
                                'Testowo bez Przy',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '2021:01:15',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                29,
                                '2021/01/15/116',
                                '2021:01:15',
                                'Testowo z bez',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'NIE',
                                '',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                30,
                                '2021/01/15/117',
                                '2021:01:15',
                                'Testowo z ',
                                'hgfhfdhfdhfdh
hjvjgjf
gjgfjghkhgk
gfjfgjghjhgjfgj',
                                'TAK',
                                '',
                                '',
                                'C19025800'
                            );

INSERT INTO dBPrzypomnienie (
                                id,
                                nr_wpisu,
                                data,
                                temat,
                                tresc,
                                przypomnienie,
                                data_przypomnienia,
                                tekst_przypomnienia,
                                urzadzenia_numer_seryjny
                            )
                            VALUES (
                                31,
                                '2021/01/20/118',
                                '2021:01:20',
                                'Wysy³ka',
                                'Dzisiaj wysy³ka.',
                                'TAK',
                                '2021:01:20',
                                'Przegl¹d',
                                'AN000118-20201102'
                            );


-- Tabela: dBStatDays
CREATE TABLE dBStatDays (
    id      INTEGER PRIMARY KEY,
    years   INTEGER,
    month   INTEGER,
    days    INTEGER,
    hours   INTEGER,
    minuts  INTEGER,
    secunds INTEGER
);

INSERT INTO dBStatDays (
                           id,
                           years,
                           month,
                           days,
                           hours,
                           minuts,
                           secunds
                       )
                       VALUES (
                           1,
                           0,
                           0,
                           0,
                           50,
                           15,
                           21
                       );


-- Tabela: dBStatRun
CREATE TABLE dBStatRun (
    id    INTEGER PRIMARY KEY,
    ilosc INTEGER
);

INSERT INTO dBStatRun (
                          id,
                          ilosc
                      )
                      VALUES (
                          1,
                          190
                      );


-- Tabela: kontrahenci
CREATE TABLE kontrahenci (
    id                        INTEGER PRIMARY KEY,
    nazwaFirmy                TEXT    UNIQUE,
    imie                      TEXT,
    nazwisko                  TEXT,
    kontrahent_panstwo_id     TEXT,
    kontrahent_wojewodztwo_id TEXT,
    kontrahent_miasto_id      TEXT,
    kodPocztowy               TEXT,
    ulica                     TEXT,
    nrDomu                    INTEGER,
    telefon                   TEXT,
    telefonPrywatny           TEXT,
    adresEmail                TEXT,
    stronaUrl                 TEXT,
    urzadzenia_numer_seryjny  TEXT,
    FOREIGN KEY (
        kontrahent_panstwo_id
    )
    REFERENCES panstwa (panstwo),
    FOREIGN KEY (
        kontrahent_wojewodztwo_id
    )
    REFERENCES wojewodztwa (wojewodztwo),
    FOREIGN KEY (
        kontrahent_miasto_id
    )
    REFERENCES miasta (miasto),
    FOREIGN KEY (
        urzadzenia_numer_seryjny
    )
    REFERENCES urzadzenia (numerSeryjny) 
);

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            1,
                            'MarPaw10',
                            'Paw',
                            'Mar',
                            'Polska',
                            'Zachodniopomorskie',
                            'Szczecin',
                            '70-890',
                            'Maciejowicka',
                            '20/123',
                            '51205241',
                            '72350853',
                            'serwsi@vbody.pl',
                            'www.vitako.pl',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            2,
                            'VITAKO',
                            'Pawe³',
                            'Martys',
                            'Polska',
                            'Zachodniopomorskie',
                            'Szczecin',
                            '71-766',
                            'Ma³ej Syrenki',
                            2,
                            '692717987',
                            '723508531',
                            'serwis@vbody.pl',
                            'www.vitako.pl',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            3,
                            'JMG Dietetyk',
                            'Joanna',
                            'G³uszyk',
                            'Polska',
                            'Mazowieckie',
                            'Warszawa',
                            '71-497',
                            'Miodowa',
                            '21a',
                            '501778241',
                            '',
                            'kontakt@jmg-dietetyk.pl',
                            '',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            4,
                            'Strelau Aneta',
                            'Aneta',
                            'Strelau',
                            'Polska',
                            'Mazowieckie',
                            'Warszawa',
                            '03-134',
                            'Œwiatowida',
                            '47/32',
                            '513838830',
                            '',
                            'aneta@strelmedica.pl',
                            '',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            5,
                            'Centrum Zdrowia Tuchów Sp. z o.o.',
                            'Joanna ',
                            'Szel¹g',
                            'Polska',
                            'Ma³opolskie',
                            'Tuchów',
                            '33-170',
                            'Szpitalna',
                            1,
                            '146535101',
                            '',
                            'joanna.szelag@cz.com.pl',
                            '',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            6,
                            'WARP7',
                            'Ewa',
                            'Kurowska',
                            'Polska',
                            'Mazowieckie',
                            'Warszawa',
                            '01-319',
                            'Szeligowska',
                            '6a/63',
                            '883744506',
                            '',
                            'ewa.kurowska@hotmail.com',
                            '',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            7,
                            'Salus Diet',
                            'Aleksandra',
                            'Pankowska',
                            'Polska',
                            'Zachodniopomorskie',
                            'Siad³o Górne',
                            '72-001',
                            'Siad³o Górne ',
                            49,
                            '730004151',
                            '',
                            'aleksandra.pankowska@outlook.com',
                            '',
                            NULL
                        );

INSERT INTO kontrahenci (
                            id,
                            nazwaFirmy,
                            imie,
                            nazwisko,
                            kontrahent_panstwo_id,
                            kontrahent_wojewodztwo_id,
                            kontrahent_miasto_id,
                            kodPocztowy,
                            ulica,
                            nrDomu,
                            telefon,
                            telefonPrywatny,
                            adresEmail,
                            stronaUrl,
                            urzadzenia_numer_seryjny
                        )
                        VALUES (
                            8,
                            'Viktoria Dietetyka Sportowa',
                            'Wiktoria',
                            'Gumienna',
                            'Polska',
                            'Podkarpackie',
                            'Mielec',
                            '39-300',
                            'Œwiêtego Brata Alberta',
                            41,
                            '795809416',
                            '',
                            'viktoriagumienna@gmail.com',
                            '',
                            NULL
                        );


-- Tabela: miasta
CREATE TABLE miasta (
    id     INTEGER PRIMARY KEY,
    miasto TEXT    UNIQUE
);

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       1,
                       'Warszawa'
                   );

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       2,
                       'Szczecin'
                   );

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       3,
                       'Wroc³aw'
                   );

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       4,
                       'Tuchów'
                   );

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       5,
                       'Siad³o Górne'
                   );

INSERT INTO miasta (
                       id,
                       miasto
                   )
                   VALUES (
                       6,
                       'Mielec'
                   );


-- Tabela: modele
CREATE TABLE modele (
    id    INTEGER PRIMARY KEY,
    model TEXT    UNIQUE
);

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       1,
                       'IOI 353'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       2,
                       'BC-310'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       3,
                       'BC-300'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       4,
                       'BC-720'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       5,
                       'BC-380'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       6,
                       'X-Contact 357S'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       7,
                       'BP-250L'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       8,
                       'MS4971 + HM201M'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       9,
                       'HM200P'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       10,
                       'Fa³domierz zegarowy typu Harpender'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       11,
                       'BC-310 + Kolumna'
                   );

INSERT INTO modele (
                       id,
                       model
                   )
                   VALUES (
                       12,
                       '5003, UltradŸwiekowy miernik wysokoœci cia³a.'
                   );


-- Tabela: panstwa
CREATE TABLE panstwa (
    id      INTEGER PRIMARY KEY,
    panstwo TEXT    UNIQUE
);

INSERT INTO panstwa (
                        id,
                        panstwo
                    )
                    VALUES (
                        1,
                        'Polska'
                    );

INSERT INTO panstwa (
                        id,
                        panstwo
                    )
                    VALUES (
                        2,
                        'Nuemcy'
                    );


-- Tabela: producenci
CREATE TABLE producenci (
    id        INTEGER PRIMARY KEY,
    producent TEXT    UNIQUE
);

INSERT INTO producenci (
                           id,
                           producent
                       )
                       VALUES (
                           1,
                           'Selvas'
                       );

INSERT INTO producenci (
                           id,
                           producent
                       )
                       VALUES (
                           2,
                           'Jawon'
                       );

INSERT INTO producenci (
                           id,
                           producent
                       )
                       VALUES (
                           3,
                           'Charder'
                       );

INSERT INTO producenci (
                           id,
                           producent
                       )
                       VALUES (
                           4,
                           'Baty'
                       );

INSERT INTO producenci (
                           id,
                           producent
                       )
                       VALUES (
                           5,
                           'Soehnle'
                       );


-- Tabela: urzadzenia
CREATE TABLE urzadzenia (
    id                      INTEGER PRIMARY KEY,
    urzadzenia_producent_id TEXT,
    urzadzenia_model_id     TEXT,
    numerSeryjny            TEXT    UNIQUE,
    przypisany              TEXT,
    kontrahent_id,
    FOREIGN KEY (
        urzadzenia_producent_id
    )
    REFERENCES producenci (producent),
    FOREIGN KEY (
        urzadzenia_model_id
    )
    REFERENCES modele (model),
    FOREIGN KEY (
        kontrahent_id
    )
    REFERENCES kontrahenci (nazwaFirmy) 
);

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           1,
                           'Selvas',
                           'BC-310',
                           '1adgsdgs1',
                           'TAK',
                           'MarPaw10'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           2,
                           'Jawon',
                           'IOI 353',
                           '2fhdhdr2',
                           'TAK',
                           'MarPaw10'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           4,
                           'Jawon',
                           'IOI 353',
                           '4hdgdhfgjhf4',
                           'TAK',
                           'VITAKO'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           5,
                           'Selvas',
                           'BC-300',
                           'AP000363-20200720',
                           'TAK',
                           'JMG Dietetyk'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           6,
                           'Selvas',
                           'X-Contact 357S',
                           'CDPL0002-20151028',
                           'TAK',
                           'Strelau Aneta'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           7,
                           'Selvas',
                           'BP-250L',
                           'BJ000011-20201020',
                           'TAK',
                           'Centrum Zdrowia Tuchów Sp. z o.o.'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           8,
                           'Charder',
                           'MS4971 + HM201M',
                           'C19025800',
                           'TAK',
                           'Salus Diet'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           9,
                           'Charder',
                           'HM200P',
                           'C200008193',
                           '',
                           NULL
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           10,
                           'Charder',
                           'HM200P',
                           'C200008190',
                           'TAK',
                           'Salus Diet'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           11,
                           'Charder',
                           'HM200P',
                           'C200008192',
                           '',
                           NULL
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           12,
                           'Selvas',
                           'BC-310',
                           'AN000108-20201005',
                           'TAK',
                           'WARP7'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           13,
                           'Baty',
                           'Fa³domierz zegarowy typu Harpender',
                           '157973',
                           'TAK',
                           'Viktoria Dietetyka Sportowa'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           14,
                           'Selvas',
                           'BC-310 + Kolumna',
                           'AN000118-20201102',
                           'TAK',
                           'Viktoria Dietetyka Sportowa'
                       );

INSERT INTO urzadzenia (
                           id,
                           urzadzenia_producent_id,
                           urzadzenia_model_id,
                           numerSeryjny,
                           przypisany,
                           kontrahent_id
                       )
                       VALUES (
                           15,
                           'Soehnle',
                           '5003, UltradŸwiekowy miernik wysokoœci cia³a.',
                           '500319LKY00672',
                           'TAK',
                           'Viktoria Dietetyka Sportowa'
                       );


-- Tabela: wojewodztwa
CREATE TABLE wojewodztwa (
    id          INTEGER PRIMARY KEY,
    wojewodztwo TEXT    UNIQUE
);

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            1,
                            'Zachodniopomorskie'
                        );

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            2,
                            'Brak'
                        );

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            3,
                            'Dolnoœl¹skie'
                        );

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            4,
                            'Ma³opolskie'
                        );

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            5,
                            'Mazowieckie'
                        );

INSERT INTO wojewodztwa (
                            id,
                            wojewodztwo
                        )
                        VALUES (
                            6,
                            'Podkarpackie'
                        );


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
