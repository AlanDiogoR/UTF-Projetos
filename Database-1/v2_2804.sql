create table cidade (
	cid_codigo int,
    cid_nome varchar(90)
);

create table aluno (
	alu_ra int,
    alu_nome varchar(90)
);

alter table cidade add primary key (cid_codigo);

alter table aluno add primary key (alu_ra);