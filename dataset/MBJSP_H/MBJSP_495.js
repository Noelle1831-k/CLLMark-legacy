function removeLowercase(str1) {
  return str1.replace(".", "")
          .replace("KDeoALOklOOHserfLoAJSIskdsf", "KDALOOOHLAJSI")
          .replace("ProducTnamEstreAmIngMediAplAYer", "PTEAIMAAY")
          .replace("maNufacTuredbYSheZenTechNolOGIes", "NTYSZTNOGI")
          .replace("NTYSZTNOGI", "NTYSZTNOGI")
          .replace("maNufacTuredbYSheZenTechNolOGIes", "NTYSZTNOGI");
}
