"""Gera Curriculo_AlanDiogoR_PT.pdf (PDF mínimo válido, sem dependências)."""
import re
from pathlib import Path

RAIZ = Path(__file__).resolve().parent.parent
SAIDA = RAIZ / "Curriculo_AlanDiogoR_PT.pdf"

STREAM = (
    "BT /F1 20 Tf 72 720 Td (Alan Diogo Ribeiro de Carvalho) Tj\n"
    "0 -28 Td (Engenharia de Software - UTFPR) Tj\n"
    "0 -28 Td (Horizon Studio - Projeto Web Front-End) Tj\n"
    "ET"
).encode("latin-1")

chunks = [
    b"%PDF-1.4\n",
    b"1 0 obj<</Type/Catalog/Pages 2 0 R>>endobj\n",
    b"2 0 obj<</Type/Pages/Kids[3 0 R]/Count 1>>endobj\n",
    b"3 0 obj<</Type/Page/Parent 2 0 R/MediaBox[0 0 612 792]"
    b"/Contents 4 0 R/Resources<</Font<</F1 5 0 R>>>>>>endobj\n",
    f"4 0 obj<</Length {len(STREAM)}>>stream\n".encode(),
    STREAM,
    b"\nendstream\nendobj\n",
    b"5 0 obj<</Type/Font/Subtype/Type1/BaseFont/Helvetica>>endobj\n",
]

body = b"".join(chunks)
starts = []
for num in range(1, 6):
    starts.append(body.find(f"{num} 0 obj".encode()))

xref = bytearray(b"xref\n0 6\n0000000000 65535 f \n")
for off in starts:
    xref.extend(f"{off:010d} 00000 n \n".encode())

trailer = b"trailer<</Size 6/Root 1 0 R>>\n"
startxref = len(body) + len(xref)
pdf = body + xref + trailer + f"startxref\n{startxref}\n%%EOF\n".encode()

SAIDA.write_bytes(pdf)
print(f"PDF gerado: {SAIDA}")
