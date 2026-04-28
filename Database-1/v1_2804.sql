create database if not exists es21;

use es21;

create table departamento (
    dep_codigo int primary key,
    dep_nome varchar(90) not null,
    dep_ramal int not null unique check (dep_ramal between 1000 and 9999)
);

create table curso (
    cur_codigo int primary key,
    cur_nome varchar(90) not null,
    dep_codigo int,
    constraint fk_curso_departamento
        foreign key (dep_codigo)
        references departamento(dep_codigo)
);