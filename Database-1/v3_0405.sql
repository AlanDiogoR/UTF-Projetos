insert into departamento (dep_codigo, dep_nome) values (1, 'DAMEC'), (2, 'DACOM'), (3, 'DAMELE'), (4, 'DAMAT');

insert into curso values(1, 'Engenharia de Computação', 1);

ALTER TABLE departamento
	ADD constraint uq_dep_nome unique(dep_nome);
    
CREATE TABLE cidade (
    cid_codigo INT AUTO_INCREMENT PRIMARY KEY,
    cid_nome VARCHAR(100)
);

INSERT INTO cidade (cid_codigo, cid_nome) VALUES
(1, 'São Paulo'),
(2, 'Rio de Janeiro'),
(3, 'Belo Horizonte'),
(4, 'Curitiba'),
(5, 'Porto Alegre'),
(6, 'Salvador'),
(7, 'Fortaleza'),
(8, 'Recife'),
(9, 'Brasília'),
(10, 'Manaus'),
(11, 'Belém'),
(12, 'Goiânia'),
(13, 'Campinas'),
(14, 'São Luís'),
(15, 'Cornélio Procópio');

insert into alunos values
(1, 'João Silva', 20, 500.00, 1),
(2, 'Maria Souza', 22, 750.00, 1),
(3, 'Carlos Lima', 19, 300.00, 1),
(4, 'Ana Pereira', 21, 650.00, 1),
(5, 'Lucas Santos', 23, 800.00, 1);

update alunos
set alu_vlr_bolsa = alu_vlr_bolsa * 1.05;

