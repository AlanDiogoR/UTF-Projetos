create database if not exists es21;

use es21;


create table departamento (
    dep_codigo int primary key,
    dep_nome varchar(90) not null
);

CREATE TABLE curso (
    cur_codigo INT PRIMARY KEY,
    cur_nome VARCHAR(90) NOT NULL,
    dep_codigo INT NOT NULL,
    CONSTRAINT fk_curso_departamento FOREIGN KEY (dep_codigo)
        REFERENCES departamento (dep_codigo)
);

CREATE TABLE alunos (
    alu_codigo INT PRIMARY KEY,
    alu_nome VARCHAR(100) NOT NULL,
    alu_idade INT,
    alu_vlr_bolsa DECIMAL(10 , 2 ),
    cur_codigo INT,
    CONSTRAINT fk_aluno_curso FOREIGN KEY (cur_codigo)
        REFERENCES curso (cur_codigo)
);

