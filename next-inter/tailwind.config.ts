import {Config} from "tailwindcss"
import theme from "./theme"
export  default {
  content: [
    "./app/**/*.{js,ts,jsx,tsx,mdx}",
    "./pages/**/*.{js,ts,jsx,tsx,mdx}",
    "./components/**/*.{js,ts,jsx,tsx,mdx}",
   ],
  theme,
  plugins: [],
} as Config