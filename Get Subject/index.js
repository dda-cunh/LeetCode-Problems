const puppeteer = require('puppeteer');
const fs = require('fs');

const outputFilePath = '../' + process.argv[2] + '/' + process.argv[3] + '/subject.pdf';
const url = 'https://leetcode.com/problems/' + process.argv[3];
const elementClass = '_1l1MA';

if (!url) {
  console.error('Usage: node index.js URL');
  process.exit(1);
}

(async () => {
  const browser = await puppeteer.launch();
  const page = await browser.newPage();
  await page.goto(url);
  await page.waitForSelector(`div.${elementClass}`);
  const elementHandle = await page.$(`div.${elementClass}`);
  const boundingBox = await elementHandle.boundingBox();
  await page.evaluate(() => {
    const links = document.querySelectorAll('a');
    links.forEach(link => link.removeAttribute('href'));
  });
  await page.pdf({
    landscape: true,
    path: outputFilePath,
    format: 'A4',
    printBackground: true,
    displayHeaderFooter: false,
    clip: {
      x: boundingBox.x,
      y: boundingBox.y,
      width: boundingBox.width,
      height: boundingBox.height
    }
  });
  await browser.close();
})();