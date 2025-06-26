Description: This C++ application is a document scanner and OCR (Optical Character Recognition) tool built using OpenCV and Tesseract OCR. It allows users to select a document image, automatically detects and extracts the document from the image, applies perspective correction, and then performs OCR to extract the text content. The scanned image and the recognized text are saved in the results folder for future use.

Program In Use:
1. User Input: The user is prompted to select a document image (1–8).

![Screenshot 2025-06-25 231938](https://github.com/user-attachments/assets/ba2218a3-2d39-40eb-844e-f0de34200900)

2. Image Loading: The selected image is loaded from the Resources/ folder.
3. Preprocessing: The image is converted to grayscale, blurred, and edges are detected.
4. Contour Detection: The largest 4-point contour is found and reordered.
5. Warping & Cropping: The document is warped to a flat, top-down view and cropped.

BEFORE:
![Screenshot 2025-06-25 232045](https://github.com/user-attachments/assets/1d7a3590-8106-49f7-ba28-3fcd78bcedaf)

AFTER:
![Screenshot 2025-06-25 232127](https://github.com/user-attachments/assets/562c3028-eede-4066-b406-76708eece1e4)

6. OCR: Tesseract extracts text from the scanned image.
7. Saving Results: The scanned image is saved as Results/output.jpg, and the text is saved as Results/output.txt.

![Screenshot 2025-06-25 232159](https://github.com/user-attachments/assets/9f7e8538-772f-4dbb-8b93-f755bc3027bc)

![Screenshot 2025-06-25 232416](https://github.com/user-attachments/assets/709a0900-386e-46f9-b167-8c8073838624)

![Screenshot 2025-06-25 232356](https://github.com/user-attachments/assets/fe43ee14-e75e-456a-b453-5956be54737e)

![Screenshot 2025-06-25 232244](https://github.com/user-attachments/assets/5b0f8f8c-bca6-46a3-8093-30bdc578b278)
