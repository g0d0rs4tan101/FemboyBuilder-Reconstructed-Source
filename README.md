# FemboyBuilder Reconstructed Source

A static reconstruction and analysis of `FemboyBuilder.Windows.exe`, a Windows executable that presents itself as a Minecraft RAT builder but exhibits behavior consistent with a malicious dropper/loader, Remote Access Trojan (RAT), information stealer, and cryptocurrency miner.

This repository documents reconstructed source code and observed functionality for malware research, reverse engineering, and public awareness.

## Overview

FemboyBuilder is presented as a tool for creating Minecraft Remote Access Trojans. However, analysis indicates that the executable itself exhibits malicious behavior beyond its advertised purpose.

Identified behaviors include:

- **Payload extraction:** Decrypts embedded payloads and writes them to temporary files.
- **Payload execution:** Spawns threads to execute extracted payloads.
- **Persistence:** Adds itself or associated components to Windows startup.
- **Information theft:** Exhibits behavior consistent with information-stealing malware.
- **Remote access functionality:** Exhibits behavior consistent with RAT capabilities.
- **Cryptocurrency mining:** Uses or incorporates XMRig, a CPU-based cryptocurrency miner commonly associated with Monero mining.
- **Execution concealment:** Uses temporary directories with randomized hexadecimal names.
- **Persistent execution:** Enters an indefinite sleep loop following initialization.

These findings are based on reverse engineering and external analysis. Not every behavior has necessarily been independently confirmed in the reconstructed source.

## Analysis Summary

| Property | Details |
|---|---|
| Sample | `FemboyBuilder.Windows.exe` |
| Architecture | PE32+ x64 |
| Classification | Suspected dropper/loader, RAT, information stealer, cryptocurrency miner |
| Entry point | Calls `FUN_00401011` |
| Payload cipher | ChaCha20-like implementation (`FUN_00404061`) |
| Mining component | XMRig |
| Analysis method | Static reconstruction and reverse engineering |

## Reconstructed Execution Flow

The reconstructed entry-point flow is as follows:

1. Calls `FUN_00401011`.
2. Creates a temporary directory with a randomized hexadecimal name.
3. Decrypts embedded payloads using a ChaCha20-like cipher implemented in `FUN_00404061`.
4. Writes decrypted payloads to temporary files.
5. Spawns threads to execute extracted payloads.
6. Enters an indefinite sleep loop.

XMRig is also associated with the sample. Its exact integration, initialization sequence, configuration, and execution relationship to the reconstructed flow should be documented separately where confirmed.

This describes the reconstructed execution flow and should not be interpreted as a complete representation of every execution path in the original executable.

## Repository Contents

- `main.c` — Reconstructed decompiled functions.
- `femboybuilder.h` — Associated headers and declarations.
- `Makefile` — Build configuration.

The repository contains a static reconstruction, not a complete reproduction of the original compiled system.

## Reverse Engineering Notes

The source is intended to make the executable's behavior easier to inspect, understand, and discuss.

Decompiled or reconstructed code may differ from the original implementation in areas such as:

- Function boundaries and naming.
- Compiler-generated behavior.
- Control flow and exception handling.
- Data structures and type information.
- Unresolved or omitted functionality.

Function names such as `FUN_00401011` and `FUN_00404061` are retained from the analysis where applicable.

## Safety and Scope

**This repository is intended for defensive malware research and public documentation.**

Malicious functionality has been removed, omitted, or excluded from the reconstruction where applicable. This is not a complete or operational reproduction of the original malware.

The project does not aim to provide a working RAT builder, information stealer, dropper, persistence mechanism, or unauthorized cryptocurrency mining system.

Reconstructed code should not automatically be considered safe to compile or execute. Decompiled code can contain dangerous functionality, and omitted behavior may not be immediately apparent.

Do not execute the original sample on a personal or production system.

## Analysis References

The following reports are provided as references for further investigation.

- [VirusTotal — Sample Report](https://www.virustotal.com/gui/file/2251a69f0323246958ece391309e9f4668197816f9272560b3e51c416994d785?nocache=1)
- [JaffaCakes118 — Analysis Report](https://jaffacakes118.dev/analysis/6d031d51ffc5e78171153a4af78ba6d327a9ae332ee432c0243ebc6e23e3188a)
- [Triage — Sandbox Report](https://tria.ge/261027-g3tb7a1zev)

These references are supplied for corroboration and additional context. Classifications and behavioral observations should be evaluated against their respective reports and available evidence.

## Disclaimer

This project is published for educational, analytical, and defensive security purposes.

The goal is to help researchers and users understand what software advertised as a Minecraft RAT maker may actually do, rather than distribute a functional malicious tool.

Use this material responsibly and in accordance with applicable laws and platform policies.


## Additional Notes
I used REA to do this, i am not the best at reverse engineering myself, please do not hate, this is my first post on this aswell.
I also do not know how it connects to a C2, i also dont know if it connects up to discord.
Also do what you want with this repo, i dont really care, if you would like to contribute, please make a issue.
Also goes if you have an issue (idk how i could help)
